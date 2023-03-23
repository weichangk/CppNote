#pragma once
namespace ns_class_01
{
  class Person
  {
  private:
    char mName[32];
    int mAge;
  public:
    Person();
    ~Person();
    void PersonInit(char *name, int age);
    void SetAge(int age);
    void SetName(char *name);
    char* GetName(void);
    void ShowPerson(void);
  };
}

