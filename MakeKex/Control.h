#include "Types.h"

class Control
{
public:
	Control();
	~Control();

	void Init();
	void Run();

	int GetKex() { return kex; }
	void SetKex(int x) { kex = x; }
	void AddKex(int x) { kex += x; }
	void Stop() { isRun = false; }
private:
	bool isRun;
	int kex;
	MakeKex *mk;
	EatKex *ek;
};
