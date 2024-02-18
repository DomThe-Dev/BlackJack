#pragma once
class Player
{
private:

public:
	int handTemp = 0;

	void handDoub(int& handTemp)
	{
		handTemp *= handTemp;
	}
};