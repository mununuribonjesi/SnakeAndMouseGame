#if !defined(UndergroundH)
#define UndergroundH

#include <cassert>
#include <vector>
using namespace std;
#include "constants.h"
#include "Hole.h"
class Underground 

{
	public:
		Underground();
		Hole get_hole_no(int no) const;
		void set_hole_no_at_position(int no, int x, int y);
		Hole hole;
		vector<Hole> holes_;
	private:
		static const int MAXHOLES=3; //number of holes in underground
		bool is_valid_hole_number(int n) const;
};

#endif // !defined(UndergroundH) 
