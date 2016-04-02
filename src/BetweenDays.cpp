/*
Q4: Two dates are given in a 8 node single linked list form,where each node
has one digit only, dates 01-31, months 01-12, year 0000-9999.

Find the number of days in between those two dates .[Exclusive]

Ex : Date1:  0->1->0->1->2->0->0->4 .
     Date2 : 0->5->0->1->2->0->0->4 should return 3 .
As there are 3 days between Jan1st 2004 and Jan 5th 2004.

Ex 2 : Date1 : 3->1->1->2->2->0->1->2.
       Date2 : 0->2->0->1->2->0->1->3 should return 1 .
(There is only one day between 31st Dec 2012 and 2nd  Jan 2013 .)

Note : Consecutive Days and Same Days should return 0;
->Return -1 for NULL Inputs .
->Between Days have to be calculated by not including start and end date .
->The SLL will have 8 Nodes in all cases . Month 9 will be represented as 09.

Difficulty : Hard 
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct node{
	int data;
	struct node *next;
};
int valid(char*);
int between_days(struct node *date1head, struct node* date2head)
{
	int check = 1, l=0, m=0, diff, day1, day2, m1, m2, yr1, yr2, count1, count2;
	char *d1, *d2;
	d1 = (char*)malloc(8 * sizeof(char));
	d2 = (char*)malloc(8 * sizeof(char));
		if (date1head&&date2head)
		{
			int len1 = 0, len2 = 0;
			struct node *current1 = NULL, *current2 = NULL;
			current1 = date1head, current2 = date2head;
			while (current1->next != NULL&&current2->next != NULL)
			{
				d1[l] = current1->data;
				current1 = current1->next;
				l++;
				d2[m] = current2->data;
				current2 = current2->next;
				m++;

			}
			check = valid(d1)*valid(d2);
			if (check)
			{
				int x, y;
				day1 = 10 * (d1[0] - '0') + d1[1] - '0';
				m1 = 10 * (d1[2] - '0') + d1[3] - '0';
				day2 = 10 * (d2[0] - '0') + d2[1] - '0';
				m2 = 10 * (d2[2] - '0') + d2[3] - '0';
				x = m1;
				y = m2;
				while (x)
				{
					if (x == 4 || x == 6 || x == 9 || x == 11)
						len1 = len1 + 30;
					else if (x == 2)
						len1 = len1 + 28;
					else
						len1 = len1 + 31;
					x--;
				}
				while (y)
				{
					if (y == 4 || y == 6 || y == 9 || y == 11)
					{
						len2 = len2 + 30;
					}
						
					else if (y == 2)
					{ 
						len2 = len2 + 28;
					}
						
					else
						len2 = len2 + 31;
					y--;
				}
				yr1 = 1000 * (d1[4] - '0') + 100 * (d1[5] - '0') + 10 * (d1[6] - '0') + (d1[7] - '0');
				yr2 = 1000 * (d2[4] - '0') + 100 * (d2[5] - '0') + 10 * (d2[6] - '0') + (d2[7] - '0');
				count1 = yr1 * 365 + len1 + day1 + yr1 / 4 - yr1 / 100;
				count2 = yr2 * 365 + len2 + day2 + yr2 / 4 - yr2 / 100;
				return (count2 - count1-1);
			}
		}
		else
		{
			return -1;
		}
}
int valid(char* a)
{
	int day, m, yr, x = 0;
	day = 10 * (a[0] - '0') + a[1] - '0';
	m = 10 * (a[2] - '0') + a[3] - '0';
	yr = 1000 * (a[4] - '0') + 100 * (a[5] - '0') + 10 * (a[6] - '0') + (a[7] - '0');
	if (yr != 0)
	{
		if (m < 13 && m>0)
		{
			if (m == 4 || m == 6 || m == 9 || m == 11)
			{
				if (day < 31 && day>0){ x = 1; }
			}
			else if (m == 2)
			{
				if ((yr % 4 == 0) && (yr % 100 != 0) || yr % 400 == 0)
				{
					if (day < 30 && day>0){ x = 1; }
				}
				else
				{
					if (day < 29 && day>0){ x = 1; }
				}
			}
			else
			{
				if (day < 32 && day>0){ x = 1; }
			}
			return x;
		}
	}
	return 0;
}
