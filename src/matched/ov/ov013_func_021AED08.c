/*
 * function: func_021AED08
 * address: 0x021AED08
 * packet: pkt_ov013_021AED08
 * region: ov013
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021AEDEC 0x021AEDEC thumb ov013
 *   func_021B0614 0x021B0614 arm ov013
 */
struct Node;
extern void func_021AEDEC(struct Node *p);
extern int func_021B0614(void *);
void func_021AED08(int unused,int code,void *p)
{
    switch(code) {
    case 9: func_021AEDEC(p); break;
    case 7: func_021B0614(p); break;
    case 12: func_021AEDEC(p); break;
    }
}
