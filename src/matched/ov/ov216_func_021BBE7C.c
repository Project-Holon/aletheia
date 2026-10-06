/*
 * unit: yes
 * function: func_021BBE7C, func_021BBF0C
 * address: 0x021BBE7C
 * packet: pkt_ov216_021BBE7C
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * follower: 021BBF0C pool-and-bx thunk forwarding to 021BCC10.
 * symbols:
 *   func_021BC3DC 0x021BC3DC thumb ov216
 *   func_021BBF28 0x021BBF28 thumb ov216
 *   func_021BBF60 0x021BBF60 thumb ov216
 *   func_021BBF14 0x021BBF14 thumb ov216
 *   func_021BBF98 0x021BBF98 thumb ov216
 *   func_021BCC10 0x021BCC10 thumb ov216
 *   func_020310C4 0x020310C4 arm
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_021BC920 0x021BC920 thumb ov216
 *   func_021BCA24 0x021BCA24 thumb ov216
 */
#include "../include/Obj03374.h"
struct Tcbl; struct PrintSys;
extern void func_021BC3DC(void *);
extern int func_021BBF28(unsigned char *p);
extern int func_021BBF60(char *);
extern int func_021BBF14(char *);
extern int func_021BBF98(char *);
extern int func_021BCC10(unsigned char *);
extern void func_020310C4(struct Tcbl *);
extern unsigned func_0201C4E4(struct PrintSys *);
extern int func_021BC920(unsigned *);
extern void func_021BCA24(char *);
int func_021BBF0C(char *);
int func_021BBE7C(int unused0,int *state,int unused2,char *p)
{
    if (((struct Obj03374 *)p)->f10) return 1;
    if (*state>=2 && *state<=3) func_021BC3DC(((struct Obj03374 *)p)->f124);
    switch (*state) {
    case 0: *state=func_021BBF28((unsigned char *)p); break;
    case 1: *state=func_021BBF60(p); break;
    case 2: *state=func_021BBF0C(p); break;
    case 3: *state=func_021BBF14(p); break;
    case 4: *state=func_021BBF98(p); break;
    case 5: return 1;
    }
    func_020310C4(*(struct Tcbl * *)&((struct Obj03374 *)p)->f18);
    func_0201C4E4(*(struct PrintSys * *)&((struct Obj03374 *)p)->f12C);
    func_021BC920((unsigned *)p);
    func_021BCA24(*(char * *)&((struct Obj03374 *)p)->f50);
    return 0;
}
int func_021BBF0C(char *p)
{
    return func_021BCC10((unsigned char *)p);
}
