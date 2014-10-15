#include <iostream>

template <typename T>
class WinnerT{ 
private:
	T * tree;
	size_t size;
	T eliminate_player_sig;
public:
	WinnerT(T * scores, int players, T elim){
		this->size = (players * 2);
		eliminate_player_sig = elim;
		tree = new T[this->size];
		

		//figure out placement of array
		for (int i = players; i < this->size; ++i){
			tree[i] = scores[i - players];
		}

		for (int = players - 1;)

	}

	~WinnerT(){

	}

	T winner(){ return eliminate_player; }
	void eliminate_player(int player){ }
	int get_size(){ return (int)(size - 1); }
	bool empty(){ return false; }
	void pretty_print(std::ostream&){}



};