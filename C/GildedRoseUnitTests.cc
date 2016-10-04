#include <CppUTest/TestHarness.h>
#include <CppUTest/CommandLineTestRunner.h>
#include <CppUTestExt/MockSupport.h>

extern "C" {
#include "GildedRose.h"
}

TEST_GROUP(TestGildedRoseGroup)
{
  void setup() {
  }
  void teardown() {
  }
};

TEST(TestGildedRoseGroup, ConjuredQualityDrops2xNormalBeforeSellIn)
{
    Item items[2];
    init_item(&items[0], "Elixir of the Mongoose", 5, 7);
    init_item(&items[1], "Conjured Mana Cake", 3, 6);

    update_quality(items, 2);

    LONGS_EQUAL(7 - 1, items[0].quality);
    LONGS_EQUAL(6 - 2, items[1].quality);
}

TEST(TestGildedRoseGroup, ConjuredQualityDrops2xNormalAfterSellIn)
{
    Item items[2];
    init_item(&items[0], "Elixir of the Mongoose", 0, 7);
    init_item(&items[1], "Conjured Mana Cake", 0, 6);

    update_quality(items, 2);

    LONGS_EQUAL(7 - 2, items[0].quality);
    LONGS_EQUAL(6 - 4, items[1].quality);
}

int
main(int ac, char** av)
{
  return CommandLineTestRunner::RunAllTests(ac, av);
}
