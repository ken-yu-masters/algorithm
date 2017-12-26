#include <QTextStream>

extern int unitTest();

int main (int argc, char * argv[])
{
  QTextStream cin(stdin);
  QTextStream cout(stdout);

  cout << "******* start unit test *******" << endl;

  unitTest();
	return 0;
}