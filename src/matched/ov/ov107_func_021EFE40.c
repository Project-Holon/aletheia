/*
 * function: func_021EFE40
 * address: 0x021EFE40
 * packet: pkt_ov107_021EFE40
 * region: ov107
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * evidence: caller-only TU/split was MATCH with nine overlay-only leaves;
 * parent-cleared 60-byte getter unit10D4 and standalone1B08 each verified
 * before unchanged caller re-run EXACT. Case18 is empty; case19 stores22.
 * prototype: own legacy02012DAC has three unused trailing parameters;
 * original supplies only r0; full body forwards only r0 to02012CE0 and
 * no inputs to0201042C, then replaces r0/r1 before remaining calls.
 * symbols:
 *   func_021F1B08 0x021F1B08 thumb ov107
 *   func_021F1B14 0x021F1B14 thumb ov107
 *   func_021F10D4 0x021F10D4 thumb ov107
 *   func_021F10DC 0x021F10DC thumb ov107
 *   func_021F10E4 0x021F10E4 thumb ov107
 *   func_021F10EC 0x021F10EC thumb ov107
 *   func_021F10F4 0x021F10F4 thumb ov107
 *   func_021F10FC 0x021F10FC thumb ov107
 *   func_021F1104 0x021F1104 thumb ov107
 *   func_021F110C 0x021F110C thumb ov107
 *   func_021F11F0 0x021F11F0 thumb ov107
 *   func_020056EC 0x020056EC thumb
 *   func_02012DAC 0x02012DAC thumb
 *   func_02012DD0 0x02012DD0 thumb
 */
#include "../include/Obj01529.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_021F1B08(void *),func_021F1B14(void *);
extern int func_021F10D4(void *),func_021F10DC(void *),func_021F10E4(void *),func_021F10EC(void *);
extern int func_021F10F4(void *),func_021F10FC(void *),func_021F1104(void *),func_021F110C(void *);
extern int func_021F11F0(void *,u8,u32);
extern u32 func_020056EC(u32);
extern int func_02012DAC(int);
extern int func_02012DD0(u8 *);
#define OBJ (*(void **)(p+0xc))
#define MSG (*(void **)(p+0x68))
#define TARGET (*(u8 **)(*(u8 **)(p+8)+4))
void func_021EFE40(u8 *p)
{
    switch(p[0x24]) {
    case 9:
        if(func_021F1B08(MSG)==1 && func_021F1B14(MSG)==1 && func_021F10D4(OBJ)==1) {
            if(func_021F11F0(OBJ,1,func_020056EC(20)+10)==1) p[0x24]=10;
        }
        break;
    case 10: if(func_021F10F4(OBJ)==1) p[0x24]=11; break;
    case 11: func_02012DAC((int)TARGET); p[0x24]=12; break;
    case 12: if(func_02012DD0(TARGET)==1) p[0x24]=13; break;
    case 13:
        if(func_021F10DC(OBJ)==1 && func_021F11F0(OBJ,2,func_020056EC(20)+10)==1) {
            p[0x24]=14; p[0x27]=0;
        }
        break;
    case 14:
        if(func_021F10FC(OBJ)==1) {
            p[0x27]++;
            if(p[0x27]>(u32)func_021F110C(OBJ)) p[0x24]=15;
        }
        break;
    case 15: if(func_02012DD0(TARGET)==2) p[0x24]=16; break;
    case 16:
        if(func_021F10E4(OBJ)==1 && func_021F11F0(OBJ,3,0)==1) {
            p[0x24]=17; p[0x27]=0;
        }
        break;
    case 17:
        if(func_021F10EC(OBJ)==1 && func_021F11F0(OBJ,4,0)==1) p[0x24]=19;
        break;
    case 18: break;
    case 19: if(func_021F1104(OBJ)==1) ((struct Obj01529 *)p)->f20=22; break;
    }
}
