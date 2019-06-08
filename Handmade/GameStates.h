#pragma once
class GameStates
{
public:
	GameStates(GameStates* preaviusState) { m_preaviusState = preaviusState; }
	virtual ~GameStates() = 0;
public:
	void SetAlive(bool flag) { m_isAlive = flag; }
	void SetActive(bool flag) { m_isActive = flag; }

	bool isActive() { return m_isActive; }
	bool isAlive() { return m_isAlive; }

	virtual void Update() = 0;
	virtual void Draw() = 0;

	//virtual bool OnEnter() = 0;
	//virtual bool OnExit() = 0;

protected:
	bool m_isAlive = true;
	bool m_isActive = true;
	GameStates* m_preaviusState;
};

