#include <iostream>
#include "KQueue.h"

template <typename T>
class WinnerT{ 
private:
	T * tree;
	size_t size;
	char eliminate_player_sig;
public:
	WinnerT(T * scores, size_t players, char elim){
		this->size = (players * 2);
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
		position = position / 2;
		tree[player] = new_score;
		bool updating = true;
		while (updating){
			std::cout << "updating" << std::endl;
			//reevaluate tree[2*position] & tree[2*position + 1]
			tree[position] = tree[position * 2] > tree[position * 2 + 1] ? tree[position * 2] : tree[position * 2 + 1];
			player = position;
			position = position / 2;
			if (position == 0){
				updating = false;
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


		int players = size / 2;
		int tree_height = findHeight(players);
		int start_matches = (int)pow(2, tree_height - 2);
		std::cout << "TREE HEIGHT: " << tree_height << std::endl;
		int height = ((players * 2) - 2) + 1;
		int width = ((tree_height - 1) * 3) + 1;

		std::cout << height << std::endl << std::endl;
		KQueue<int>* ino = inorder();	

		

		for (int i = -1; i < height; ++i){
			if (i == -1){
				std::cout << " ";
			}
			else{
				std::cout << i;
			}
			for (int j = 0; j < width; ++j){
				if (i == -1){ std::cout << j; }

				if (i != -1){
					if (!ino->isEmpty()){
						if (i % 2 == 0)
						{
							if (j == width - 1){
								std::cout << ino->dequeue();
							}else{
								std::cout << " ";
							}
						}
						else{
							if ((j == height - 4 && i != width/2) || (i == (players - 1) && j == 0)){
								std::cout << ino->dequeue();
							}
							else{
								std::cout << "-";
							}
						}
					}
				}


				
			}
			std::cout << std::endl;
		}







	}


private:

	KQueue<int>* inorder(){
		KQueue<int>* ino = new KQueue<int>;
		inorder(*ino, 1);
		return ino;
	}

	void inorder(KQueue<int>& ino, int position){

		if (position * 2 < size){
			inorder(ino, position * 2);
		}

		ino.enqueue(tree[position]);
		std::cout << tree[position] << std::endl;
		if (position * 2 + 1 < size){
			inorder(ino, position * 2 + 1);
		}



	}



	int findHeight(int size){
		if (size == 0)
			return 0;
		else{
			return 1 + findHeight(size / 2);
		}
	}



};