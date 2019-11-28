#include "Shim.h"

int main()
{
	Console.WriteLine();
	String[] arguments = Environment.GetCommandLineArgs();
	Console.WriteLine("GetCommandLineArgs: {0}", String.Join(", ", arguments));
}