/*
 * function: func_021BDB54
 * address: 0x021BDB54
 * packet: pkt_ov208_021BDB54
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: 021BDB9E..021BDBA0 is two-byte zero alignment padding.
 * matching: initialize the byte counter before reading the bound.
 * symbols:
 *   func_021BD308 0x021BD308 thumb ov208
 */
#include "../include/Obj10896.h"
#include "../include/Obj14650.h"
struct Ov208Mgr;
extern int func_021BD308(struct Ov208Mgr *m);
struct State { char pad[0x68]; unsigned char count; };
unsigned func_021BDB54(const struct State *p)
{
    int key=func_021BD308((struct Ov208Mgr *)(*(char * *)&((struct Obj10896 *)p)->f30));
    unsigned result=0;
    unsigned char i;
    unsigned count;
    char *entry;
    if(key!=-1) {
        switch(((struct Obj10896 *)p)->f10) {
        case 0: case 1: case 2:
            i=0;
            count=p->count;
            for(;i<count;i++) {
                entry=*(char **)((char *)p+i*8+0x6c);
                if(key==((struct Obj14650 *)entry)->f0) { result=((struct Obj14650 *)entry)->f10; break; }
            }
            break;
        }
    }
    return result;
}
