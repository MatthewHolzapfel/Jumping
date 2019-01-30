#pragma once
template <class T>
class Single
{
public:
	static T* Instance();
};

template <class T>
T* Single<T>::Instance()
{
	static T* i = new T();
	
	return i;
}

