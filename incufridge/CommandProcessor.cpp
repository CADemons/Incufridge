#include "project.h"

CommandProcessor::CommandProcessor(char endOfCommand, int maxCommandLength, int first){
  m_first = first;
  m_index=m_first;
  m_lookupIndex = 0;
  m_endOfCommand = endOfCommand;
}

void CommandProcessor::AddCommand(func command, String name){
  m_lookupCommands[m_lookupIndex] = command;
  m_lookupStrings[m_lookupIndex] = name;
  m_lookupIndex += 1;
}

void CommandProcessor::AddCharacterToCommand(char nextCharacter) {
  command += String(nextCharacter);
}

void CommandProcessor::ProcessCommand() {
  int nextCharacter;
  if(Serial.available() > 0)
  { 
    nextCharacter = Serial.read();
    if ((nextCharacter >= ' ') && (nextCharacter <= '~'))
    { 
      AddCharacterToCommand(nextCharacter);
      if (nextCharacter == m_endOfCommand)
      {
        //look up Command
        //AddCharacterToCommand(m_endOfString);
        String mainCommand = command;
        if(command.indexOf(" ") != -1){
        mainCommand = command.substring(0, command.indexOf(" "));
        SplitString(command.substring(command.indexOf(" ")+1),' ');
        }
        m_index = m_first;
        int found=0;
        for(int i=0; i < m_lookupIndex; i++){
          if(m_lookupStrings[i].equals(mainCommand)){
            found=1;
            m_lookupCommands[i](m_args);
          }
        }
        if(found == 0){
          Serial.println("Command not found.");
        }
        command = "";
      }
    
    }
  }
}

void CommandProcessor::SplitString(String input, char splitter){
    int count=0;
    while(input.indexOf(splitter) != -1){
      m_args[count]=input.substring(0,input.indexOf(splitter));\
      input = input.substring(input.indexOf(splitter)+1);
      count++;
    }
    m_args[count] = input;
  }

/*
Revision history:
1. Created -Linc
2. Cleaned up names, old comments -Linc
*/
