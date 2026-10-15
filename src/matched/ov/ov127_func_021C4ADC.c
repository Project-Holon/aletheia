/*
 * function: WF2DMAP_OBJ_GetCurrentPos
 * address: 0x021C4ADC
 * packet: pkt_ov127_021C4ADC
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WF2DMAP_OBJ_GetSlot 0x021C49A4 thumb ov127
 *   WF2DMAP_OBJ_GetPos 0x021C4AC4 thumb ov127
 *   WF2DMAP_OBJ_GetDestPos 0x021C4AD0 thumb ov127
 */
typedef unsigned char u8;
typedef signed short s16;
struct pair { s16 a, b; };
extern int WF2DMAP_OBJ_GetSlot(u8 *, unsigned int);
extern struct pair WF2DMAP_OBJ_GetPos(char *);
extern struct pair WF2DMAP_OBJ_GetDestPos(char *);
struct pair WF2DMAP_OBJ_GetCurrentPos(char *p)
{
    int n = WF2DMAP_OBJ_GetSlot((u8 *)p, 8);
    int d = WF2DMAP_OBJ_GetSlot((u8 *)p, 9);
    struct pair a = WF2DMAP_OBJ_GetPos(p);
    struct pair b = WF2DMAP_OBJ_GetDestPos(p);
    a.a -= b.a;
    a.b -= b.b;
    if (n > 0) {
        a.a = n * a.a / d;
        a.b = n * a.b / d;
    } else {
        a.a = 0;
        a.b = 0;
    }
    a.a += b.a;
    a.b += b.b;
    return a;
}
