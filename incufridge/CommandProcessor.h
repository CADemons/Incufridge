//**************************************************************************
//
//				COPYRIGHT NOTICE
//			Copyright 2013 CONCORD ACADEMY
//		This program is the property of CONCORD ACADEMY
//		Any unauthorized use or duplication is prohibited
//
//**************************************************************************
//
//  Title		CommandProcessor Class
//  Filename		CommandProcessor.h
//  Originator  	Linc Berkley
//  Archive Location	https://github.com/CADemons/Incufridge/blob/master/incufridge/CommandProcessor.h
//  Version		-
//
//  Overview		Provides framework for the CommandProcessor class, which allows
//                      the computer to process commands given by the user.
//**************************************************************************
#ifndef COMMANDPROCESSOR_H
#define COMMANDPROCESSOR_H

typedef void (*func)(String*);

class CommandProcessor {
public:
  CommandProcessor(char endOfCommand, int maxCommandLength, int first);
  void AddCommand(func command, String name);
  void ProcessCommand();
  void ProcessCharacter(char in);
  String command;
private:
  void SplitString(String input, char splitter);
  void AddCharacterToCommand(char nextCharacter);
  char m_endOfCommand;
  int  m_maxCommandLength;
  int m_first;
  int m_index;
  func m_lookupCommands[30];
  String m_lookupStrings[30];
  int m_lookupIndex;
  String m_args[20];
};

//**************************************************************************
//Revision history:
//1. Created -Linc
//2. Cleaned up names, wrappers -Linc
//**************************************************************************

#endif
