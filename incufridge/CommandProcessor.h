typedef void (*func)(String*);

class CommandProcessor{
  public:
  CommandProcessor(char endOfCommand, int maxCommandLength, int first);
  void AddCommand(func command, String name);
  void ProcessCommand();
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
  String args[20];
};
