#pragma once

template <typename T>
class Singleton
{
public:
	Singleton() {}
	~Singleton() {}

	static T* GetInstance()
	{
		static T instance;
		return &instance;
	}
};

