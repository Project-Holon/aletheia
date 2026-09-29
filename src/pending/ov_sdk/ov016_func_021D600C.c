struct COORD { unsigned short x, y; };
struct RECT { struct COORD p; struct COORD q; };
void func_021D600C(struct COORD *coord, struct COORD *size, struct RECT *rect)
{
struct COORD c, s; c = *coord; s = *size; rect->p.x = c.x; rect->p.y = c.y; rect->q.x = c.x + s.x; rect->q.y = c.y + s.y;
}
