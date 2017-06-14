#pragma once

template<typename DATA>
class CQueue
{

	DATA *m_pData;
	int m_nCount;
	int m_nHead, m_nTail;
public:
	CQueue(int nCount = 5){
		m_pData = new DATA[nCount];
		m_nHead = m_nTail = 0;
		m_nCount = nCount;
	}

	void push(const DATA &data){
		if (isFull())
			return;

		m_pData[m_nTail] = data;
		if (++m_nTail > m_nCount)
			m_nTail = 0;
	}

	bool pop(DATA& data){
		if (isEmpty())
			return false;

		data = m_pData[m_nHead];
		if (++m_nHead > m_nCount)
			m_nHead = 0;
	}

	bool isFull(){
		return (m_nTail + 1) % m_nCount == m_nHead;
	}

	bool isEmpty(){
		return m_nHead == m_nTail;
	}
};

