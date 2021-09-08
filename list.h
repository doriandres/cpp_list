#ifndef LIST_H
#define LIST_H

namespace list{
	struct List {
		int* value{ nullptr };
		List* next{ nullptr };
	};

	void set(List& list, int index, int value);

	int get_undefined();

	int get(List& list, int index);

	int count(List& list);

	void add(List& list, int value);

	void del(List& list);

	void del(List& list, int index);
}

#endif