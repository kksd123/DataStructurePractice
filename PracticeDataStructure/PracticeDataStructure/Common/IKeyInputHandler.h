#pragma once
#include <Windows.h>

class IKeyInputHandler
{
public:
	virtual ~IKeyInputHandler() = default;

	void Run()
	{
		m_bRunning = true;

		while (m_bRunning)
		{
			if (GetAsyncKeyState(VK_LEFT) & 1)
				OnLeftKey();
			else if (GetAsyncKeyState(VK_RIGHT) & 1)
				OnRightKey();
			else if (GetAsyncKeyState(VK_ESCAPE) & 1)
				Stop();
		}
	}

	void Stop() { m_bRunning = false; }

protected:
	virtual void OnLeftKey() = 0;
	virtual void OnRightKey() = 0;

private:
	bool m_bRunning = false;
};