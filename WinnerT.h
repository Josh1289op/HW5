#include <iostream>

template <typename T>
class WinnerT{ 
private:
	T * tree;
	size_t size;
	char eliminate_player_sig;
public:
	WinnerT(T * scores, size_t players, char elim){
		this->size = (players * 2);
		std::cout << "SIZE: " << size << std::endl;
		eliminate_player_sig = elim;
		tree = new T[this->size + 1];
		

		//TODO: figure out placement of array
		for (int i = players; i < (int)this->size + 1; ++i){
			tree[i] = scores[i - players];
		}
		for (int i = players - 1; i > 0; --i){
			tree[i] = tree[i * 2] > tree[i * 2 + 1] ? tree[i * 2] : tree[i * 2 + 1];
		}
	}

	~WinnerT(){
		delete[] tree;
	}

	
	void update_player(int player, int new_score){
		int position = (size / 2 - 1) + player;
		player = position;
		bool updating = true;
		while (updating){
			if (tree[position] < tree[position / 2]){
				//do nothing,
				tree[position] = new_score;
				updating = false;
				std::cout << tree[position] << " " << tree[position / 2] << std::endl;
			}
			else{
				tree[player] = new_score;
				position = position / 2;
				tree[position] = tree[position * 2] > tree[position* 2 + 1] ? tree[position * 2] : tree[position * 2 + 1];
				std::cout << "UPDATING SCORE" << std::endl;
				if (position == 0 ){
					updating = false;
				}
			}
		}
	}

	void eliminate_player(int player){
		int position = (size / 2 - 1) + player;
		bool updating = true;
		if (tree[position] < tree[position / 2]){
			//do nothing
			updating = false;
		}
		else{
			std::cout << "UPDATING!!!" << std::endl;
			update_player(player, NULL);
		}

		tree[position] = NULL;
	}




	T winner(){ return tree[1]; }
	int get_size(){ return (int)(size); }
	bool empty(){ return size > 0 ? true : false; }
	void pretty_print(std::ostream&){
		//fake print for now;
		for (int i = 0; i < (int)size; ++i){
			if (i == 1){
				std::cout << "Winner: " << " " << tree[i] << std::endl;
			}
			else if (tree[i] == NULL){
				std::cout << eliminate_player_sig << std::endl;
			}
			else {
				std::cout << tree[i] << std::endl;
			}
		}

	}



};