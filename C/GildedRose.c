#include <stdbool.h>
#include <string.h>
#include "GildedRose.h"

Item*
init_item(Item* item, const char *name, int sellIn, int quality)
{
    item->sellIn = sellIn;
    item->quality = quality;
    item->name = strdup(name);
    
    return item;
}

bool isnt_brie_or_backstage_passes(Item item)
{
    return (strcmp(item.name, "Aged Brie")
            && strcmp(item.name, "Backstage passes to a TAFKAL80ETC concert"));
}

bool is_sulfuras(Item item)
{
    return (strcmp(item.name, "Sulfuras, Hand of Ragnaros"));
}

void update_quality(Item items[], int size) 
{
    int i;
    
    for (i = 0; i < size; i++)
    {
        if (isnt_brie_or_backstage_passes(items[i]))
        {
            if (items[i].quality > 0)
            {
                if (is_sulfuras(items[i]))
                {
                    items[i].quality = items[i].quality - 1;
                }
            }
        }
        else
        {
            if (items[i].quality < 50)
            {
                items[i].quality = items[i].quality + 1;

                if (!strcmp(items[i].name, "Backstage passes to a TAFKAL80ETC concert"))
                {
                    if (items[i].sellIn < 11)
                    {
                        if (items[i].quality < 50)
                        {
                            items[i].quality = items[i].quality + 1;
                        }
                    }

                    if (items[i].sellIn < 6)
                    {
                        if (items[i].quality < 50)
                        {
                            items[i].quality = items[i].quality + 1;
                        }
                    }
                }
            }
        }

        if (strcmp(items[i].name, "Sulfuras, Hand of Ragnaros"))
        {
            items[i].sellIn = items[i].sellIn - 1;
        }

        if (items[i].sellIn < 0)
        {
            if (strcmp(items[i].name, "Aged Brie"))
            {
                if (strcmp(items[i].name, "Backstage passes to a TAFKAL80ETC concert"))
                {
                    if (items[i].quality > 0)
                    {
                        if (strcmp(items[i].name, "Sulfuras, Hand of Ragnaros"))
                        {
                            items[i].quality = items[i].quality - 1;
                        }
                    }
                }
                else
                {
                    items[i].quality = items[i].quality - items[i].quality;
                }
            }
            else
            {
                if (items[i].quality < 50)
                {
                    items[i].quality = items[i].quality + 1;
                }
            }
        }
    }
}
