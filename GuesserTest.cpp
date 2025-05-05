/**
 * Unit Tests for the class
**/

#include <gtest/gtest.h>
#include "Guesser.h"

class GuesserTest : public ::testing::Test
{
	protected:
		GuesserTest(){} //constructor runs before each test
		virtual ~GuesserTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(GuesserTest, passwords_match){
	Guesser g("test");
	ASSERT_TRUE(g.match("test"));
}

TEST(GuesserTest, wrong_guess){
	Guesser g("test");
	ASSERT_FALSE("tesa");
}

TEST(GuesserTest, wrong_guess_increments_down){
	Guesser g("test");
	g.match("tesa");
	ASSERT_EQ(g.remaining(),2);
}

TEST(GuesserTest, cant_use_word_after_3_guesses){
	Guesser g("test");
	g.match("tesa");
	g.match("tesb");
	g.match("tesc");
	ASSERT_FALSE(g.match("test"));
}

TEST(GuesserTest,remaining_resets){
	Guesser g("test");
	g.match("tesa");
	g.match("tesb");
	g.match("test");

	ASSERT_EQ(g.remaining(),3);
}

TEST(GuesserTest, brute_force_lock){
	Guesser g("test");
	ASSERT_FALSE(g.match("csuchico"));
	ASSERT_FALSE(g.match("test"));
}

TEST(GuesserTest, calculate_distance){
	Guesser g("test");
	ASSERT_EQ(g.distance("test"),0);
	ASSERT_EQ(g.distance("tesa"),1);
	ASSERT_EQ(g.distance("tes"),1);
	ASSERT_EQ(g.distance("teaa"),2);
	ASSERT_EQ(g.distance("te"),2);
}


