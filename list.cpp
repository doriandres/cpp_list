#include "list.h"

namespace list {
	void set(List& list, int index, int value) {
		List* current_el{ &list };
		int current_index{ 0 };
		while (true) {
			if (current_index == index) {
				current_el->value = new int;
				*current_el->value = value;
				break;
			}
			if (current_index != index) {
				if (!current_el->next) {
					current_el->next = new List;
				}
				current_el = current_el->next;
			}
			++current_index;
		}
	}

	static int get_undefined() {
		int* undefined_ptr{ new int };
		int undefined{ *undefined_ptr };
		delete undefined_ptr;
		return undefined;
	}

	int get(List& list, int index) {
		List* current_el{ &list };
		int current_index{ 0 };
		while (true) {
			if (current_index == index) {
				if (!current_el->value) {
					return get_undefined();
				}
				return *current_el->value;
			}
			if (current_index != index) {
				if (!current_el->next) {
					return get_undefined();
				}
				current_el = current_el->next;
			}
			++current_index;
		}
	}

	int count(List& list) {
		List* prev{ &list };
		List* current{ prev->next };
		int current_count{ 1 };

		if (!current) {
			return prev->value ? 1 : 0;
		}

		while (current) {
			prev = current;
			current = current->next;
			++current_count;
		}

		return current_count;
	}

	void add(List& list, int value) {
		int index{ count(list) };
		set(list, index, value);
	}

	void del(List& list) {
		List* head{ &list };
		List* current{ head->next };

		if (head->value) {
			delete head->value;
			head->value = nullptr;
		}

		if (head->next) {
			head->next = nullptr;
		}

		while (current) {
			if (current->value) {
				delete current->value;
				current->value = nullptr;
			}

			List* next = current->next;
			current->next = nullptr;

			delete current;

			current = next;
		}
	}

	void del(List& list, int index) {
		List* current_el{ &list };
		int current_index{ 0 };
		while (true) {
			if (current_index == index) {
				delete current_el->value;
				current_el->value = nullptr;
				break;
			}
			if (current_index != index) {
				if (!current_el->next) {
					return;
				}
				current_el = current_el->next;
			}
			++current_index;
		}
	}
}