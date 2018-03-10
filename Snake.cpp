// Snake.cpp: implementation of the Snake class
#include "constants.h"
#include "Mouse.h"
#include "RandomNumberGenerator.h"
#include "Snake1.h"
Snake::Snake():MoveableGridItem(get_x(),get_y(),SNAKEHEAD)
{
	setPrivateMember(rng_.get_random_value(SIZE), rng_.get_random_value(SIZE));
	p_mouse_ = (nullptr);
}

bool Snake::has_caught_mouse() 
{
	return is_at_position(p_mouse_->get_x(), p_mouse_->get_y());
}

/* i have put a constant on the pointer 
so that p_mouse in the parameter cant not alter p_mouse */

void Snake::spot_mouse(Mouse* const p_mouse) 
{
	assert(p_mouse != nullptr);	 //Pre-condition: The mouse needs to exist 
	p_mouse_ = p_mouse;
}

void Snake::chase_mouse() 
{	 
	int snake_dx, snake_dy;
	//identify direction of travel
	
	set_direction(snake_dx, snake_dy);
	
	//go in that direction
	update_position(snake_dx, snake_dy);
	moveTail(snake_dx, snake_dy);
	
}

void Snake::set_direction(int& dx, int& dy)
{
	assert(p_mouse_ != nullptr);  //Pre-condition: The snake needs to know where the mouse is 
	//assume snake only move when necessary
	dx = 0; dy = 0;
		//update coordinate if necessary
	if (get_x() < p_mouse_->get_x())              //if snake on left of mouse
		dx = 1;                          //snake should move right
	else                                    //otherwise
		if (get_x() > p_mouse_->get_x())         //if snake on left of mouse
			dx = -1;  //snake should move left

	if (get_y() < p_mouse_->get_y())             //if snake is above mouse
		dy = 1;                          //snake should move down
	else                                    //otherwise
		if (get_y() > p_mouse_->get_y())         //if snake is below mouse
			dy = -1;                     //snake should move up
}

void Snake::moveTail(int snake_dx, int snake_dy)
{
	const int maxTail = 3;
	if (tail_.size() != maxTail)
	{
		MoveableGridItem mvGridItem = MoveableGridItem(get_x(), get_y(), Tail);
		tail_.insert(tail_.end(), mvGridItem);	
	}

		if (tail_.size() == 1)
		{
			tail_.at(0).setPrivateMember(get_x() - snake_dx, get_y() - snake_dy); //set first tail piece to heads previous position
		}
		else if (tail_.size() == 2)
		{
			tail_.at(1).setPrivateMember(tail_.at(0).get_x(), tail_.at(0).get_y()); //set second tail piece to first tail pieces previous position
			tail_.at(0).setPrivateMember(get_x() - snake_dx, get_y() - snake_dy); //set first tail piece to heads previous position
		}
		else if (tail_.size() == 3)
		{
			tail_.at(2).setPrivateMember(tail_.at(1).get_x(), tail_.at(1).get_y());//set third tail piece to second tail pieces previous position
			tail_.at(1).setPrivateMember(tail_.at(0).get_x(), tail_.at(0).get_y()); //set second tail piece to first tail pieces previous position
			tail_.at(0).setPrivateMember(get_x() - snake_dx, get_y() - snake_dy); //set first tail piece to heads previous position
		}
		
}

char Snake::getTailSymbol()
{
	return tail_.at(0).get_symbol();
}

bool Snake::gridAtTail(int row, int col)
{
	bool success = false;
	for (int i = 0; i < tail_.size(); i++)
	{
		if (row == tail_.at(i).get_y() && col == tail_.at(i).get_x())
		{
			success = true;
		}
	}
	return success;
}



