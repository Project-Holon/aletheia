/*
 * function: ZUKAN_DETAIL_TOUCHBAR_GetPressedButtonId
 * address: 0x021BDB08
 * packet: pkt_ov208_021BDB08
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: 021BDB52..021BDB54 is two-byte zero alignment padding.
 * matching: initialize the byte counter before reading the count, keeping its address in r3.
 * symbols:
 *   ZKND_TBAR_GetPressedKey 0x021BD2E0 thumb ov208
 */
#include "../include/Obj10895.h"
#include "../include/Obj14649.h"
extern int ZKND_TBAR_GetPressedKey(char *);
struct State { char pad[0x68]; unsigned char count; };
unsigned ZUKAN_DETAIL_TOUCHBAR_GetPressedButtonId(const struct State *p)
{
    int key=ZKND_TBAR_GetPressedKey(*(char * *)&((struct Obj10895 *)p)->f30);
    unsigned result=0;
    unsigned char i;
    unsigned count;
    char *entry;
    if(key!=-1) {
        switch(((struct Obj10895 *)p)->f10) {
        case 0: case 1: case 2:
            i=0;
            count=p->count;
            for(;i<count;i++) {
                entry=*(char **)((char *)p+i*8+0x6c);
                if(key==((struct Obj14649 *)entry)->f0) { result=((struct Obj14649 *)entry)->fC; break; }
            }
            break;
        }
    }
    return result;
}
