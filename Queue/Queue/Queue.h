#pragma once

template<typename DATA>
class CQueue
{

	DATA *m_pData;
	int m_nCount;
	int m_nHead, m_nTail;
public:
	CQueue(int nCount = 5);

	void push(const DATA &data);

	bool pop(DATA& data);

	bool isFull(){
		return (m_nTail + 1) % m_nCount == m_nHead;
	}

	bool isEmpty(){
		return m_nHead == m_nTail;
	}
};

template<typename DATA>
CQueue<DATA>::CQueue(int nCount){
	m_pData = new DATA[nCount];
	m_nHead = m_nTail = 0;
	m_nCount = nCount;
}

template<typename DATA>
void CQueue<DATA>::push(const DATA &data){
	if (isFull())
		return;

	m_pData[m_nTail] = data;
	m_nTail = ++m_nTail%m_nCount;
}

template<typename DATA>
bool CQueue<DATA>::pop(DATA& data){
	if (isEmpty())
		return false;

	data = m_pData[m_nHead];
	m_nHead = ++m_nHead%m_nCount;
	return true;
}
