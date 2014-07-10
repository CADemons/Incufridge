//**************************************************************************
//
//				COPYRIGHT NOTICE
//			Copyright 2013 CONCORD ACADEMY
//		This program is the property of CONCORD ACADEMY
//		Any unauthorized use or duplication is prohibited
//
//**************************************************************************
//
//  Title		Command Processor
//  Filename		CommandProcessor.cpp
//  Originator  	Linc Berkley
//  Archive Location	https://github.com/CADemons/Incufridge/blob/master/incufridge/CommandProcessor.cpp
//  Version		-
//
//  Overview		Adds commands to the command processor and allows for
//                      command processing.
//**************************************************************************

#include "project.h"

/* Constructor */
CommandProcessor::CommandProcessor(char endOfCommand, int maxCommandLength, int first){
  m_first = first;
  m_index=m_first;
  m_lookupIndex = 0;
  m_endOfCommand = endOfCommand;
  command = "";
}

/* Adds a command to the command processor--associates a name with a particular method. */
void CommandProcessor::AddCommand(func command, String name){
  m_lookupCommands[m_lookupIndex] = command;
  m_lookupStrings[m_lookupIndex] = name;
  m_lookupIndex += 1;
}

/* Goes through an input command character by character and forms a command (a string). */
void CommandProcessor::AddCharacterToCommand(char nextCharacter) {
  byte test = 1;
  String temp = String(nextCharacter);
  Serial.print("Char: ");
  Serial.println(temp);
  command.concat(temp);
}

/* Checks the input command against the list of known commands. */
void CommandProcessor::ProcessCharacter(char in) {
  char nextCharacter = in;
  if ((nextCharacter >= ' ') && (nextCharacter <= '~'))
  { 
    if (nextCharacter == m_endOfCommand)
    {
      String mainCommand = command;
      if(command.indexOf(' ') != -1) {
        mainCommand = command.substring(0, command.indexOf(" "));
        Serial.print("Main command is: ");
        Serial.println(mainCommand);
        SplitString(command.substring(command.indexOf(" ")+1),' ');
        Serial.println("Arguments found");
      }
      m_index = m_first;
      int found=0;
      for(int i=0; i < m_lookupIndex; i++){
        Serial.print(mainCommand);
        Serial.print(" vs ");
        Serial.println(m_lookupStrings[i]);
        if(m_lookupStrings[i].compareTo(mainCommand) == 0){
          found=1;
          m_lookupCommands[i](m_args);
        }
      }
      if(found == 0){
        Serial.println("Command not found.");
      }
      command = "";

    }
    else{
      AddCharacterToCommand(nextCharacter);
      Serial.print("Command: ");
      Serial.println(command);
    }
  }
  else{
    Serial.println("Invalid character");
  }
}

/* Splits the command string in order to separate the command from the arguments. */
void CommandProcessor::SplitString(String input, char splitter){
  int count=0;
  while(input.indexOf(splitter) != -1){
    m_args[count]=input.substring(0,input.indexOf(splitter));
    \
      input = input.substring(input.indexOf(splitter)+1);
    count++;
  }
  m_args[count] = input;
}

//**************************************************************************
//Revision history:
//1. Created -Linc
//2. Cleaned up names, old comments -Linc
//**************************************************************************
