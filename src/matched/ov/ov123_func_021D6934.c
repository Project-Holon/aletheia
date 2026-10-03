/*
 * function: func_021D6934
 * address: 0x021D6934
 * packet: pkt_ov123_021D6934
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: bind i+20 to n before indexing, sharing its scaled address.
 * symbols:
 *   func_021D6830 0x021D6830 thumb ov123
 *   func_021D67B4 0x021D67B4 thumb ov123
 *   func_021D6720 0x021D6720 thumb ov123
 *   func_020056EC 0x020056EC thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
struct Record { void *h; u16 x,y,a,b,age,c,d,e,f,g; };
struct Obj { u8 pad[0x40f4]; struct Record records[30]; };
extern void func_021D6830(struct Record *);
extern void func_021D67B4(u8 *, int);
extern void func_021D6720(u8 *, int);
typedef unsigned int   u32;
extern u32 func_020056EC(u32 range);
void func_021D6934(struct Obj *p)
{
    int active = 0;
    int i,n;
    for (i = 0; i < 20; i++) {
        if (p->records[i].c && !p->records[i].g) {
            func_021D6830(&p->records[i]);
            active = 1;
        }
    }
    if (active == 0) {
        for (i = 0; i < 20; i++) {
            n = func_020056EC(20);
            if (!p->records[n].c && p->records[n].d) {
                p->records[n].c = 1;
                p->records[n].x = func_020056EC(128) + 64;
                p->records[n].y = 0;
                func_021D67B4((u8 *)p, n);
                break;
            }
        }
    }
    for (i = 0; i < 10; i++) {
        n = i + 20;
        if (p->records[n].c && !p->records[n].g) {
            func_021D6830(&p->records[n]);
            active = 1;
        }
    }
    if (active == 0) {
        for (i = 0; i < 10; i++) {
            n = func_020056EC(10) + 20;
            if (!p->records[n].c && p->records[n].d) {
                p->records[n].c = 1;
                p->records[n].x = func_020056EC(128) + 64;
                p->records[n].y = 0;
                func_021D6720((u8 *)p, n);
                return;
            }
        }
    }
}
