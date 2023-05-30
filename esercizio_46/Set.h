typedef struct set *SET;

SET  SETinit(int maxN);
void SETfill(SET s, Item val);
int  SETsearch(SET s, Key k);
SET  SETunion(SET s1, SET s2);
SET  SETintersection(SET s1, SET s2);
int  SETsize(SET s);
int  SETempty(SET s);
void SETdisplay(SET s);
