/*
 * function: MB_COMM_SYS_MainSave
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
 *   MB_UTIL_MSG_IsPrintQueFinished 0x021F1B08 thumb ov107
 *   MB_UTIL_MSG_IsStreamIdle 0x021F1B14 thumb ov107
 *   MB_COMM_SYS_HasKind11 0x021F10D4 thumb ov107
 *   MB_COMM_SYS_HasKind12 0x021F10DC thumb ov107
 *   MB_COMM_SYS_HasKind12Again 0x021F10E4 thumb ov107
 *   MB_COMM_SYS_HasKind14 0x021F10EC thumb ov107
 *   MB_COMM_SYS_HasKind1 0x021F10F4 thumb ov107
 *   MB_COMM_SYS_HasKind2 0x021F10FC thumb ov107
 *   MB_COMM_SYS_HasKind4 0x021F1104 thumb ov107
 *   MB_COMM_SYS_GetCount 0x021F110C thumb ov107
 *   MB_COMM_SYS_SendMessage 0x021F11F0 thumb ov107
 *   func_020056EC 0x020056EC thumb
 *   GAME_DATA_SaveStart 0x02012DAC thumb
 *   GAME_DATA_SaveMain 0x02012DD0 thumb
 */
#include "../include/Obj01529.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern int MB_UTIL_MSG_IsPrintQueFinished(void *),MB_UTIL_MSG_IsStreamIdle(void *);
extern int MB_COMM_SYS_HasKind11(void *),MB_COMM_SYS_HasKind12(void *),MB_COMM_SYS_HasKind12Again(void *),MB_COMM_SYS_HasKind14(void *);
extern int MB_COMM_SYS_HasKind1(void *),MB_COMM_SYS_HasKind2(void *),MB_COMM_SYS_HasKind4(void *),MB_COMM_SYS_GetCount(void *);
extern int MB_COMM_SYS_SendMessage(void *,u8,u32);
extern u32 func_020056EC(u32);
extern int GAME_DATA_SaveStart(int);
extern int GAME_DATA_SaveMain(u8 *);
#define OBJ (*(void **)(p+0xc))
#define MSG (*(void **)(p+0x68))
#define TARGET (*(u8 **)(*(u8 **)(p+8)+4))
void MB_COMM_SYS_MainSave(u8 *p)
{
    switch(p[0x24]) {
    case 9:
        if(MB_UTIL_MSG_IsPrintQueFinished(MSG)==1 && MB_UTIL_MSG_IsStreamIdle(MSG)==1 && MB_COMM_SYS_HasKind11(OBJ)==1) {
            if(MB_COMM_SYS_SendMessage(OBJ,1,func_020056EC(20)+10)==1) p[0x24]=10;
        }
        break;
    case 10: if(MB_COMM_SYS_HasKind1(OBJ)==1) p[0x24]=11; break;
    case 11: GAME_DATA_SaveStart((int)TARGET); p[0x24]=12; break;
    case 12: if(GAME_DATA_SaveMain(TARGET)==1) p[0x24]=13; break;
    case 13:
        if(MB_COMM_SYS_HasKind12(OBJ)==1 && MB_COMM_SYS_SendMessage(OBJ,2,func_020056EC(20)+10)==1) {
            p[0x24]=14; p[0x27]=0;
        }
        break;
    case 14:
        if(MB_COMM_SYS_HasKind2(OBJ)==1) {
            p[0x27]++;
            if(p[0x27]>(u32)MB_COMM_SYS_GetCount(OBJ)) p[0x24]=15;
        }
        break;
    case 15: if(GAME_DATA_SaveMain(TARGET)==2) p[0x24]=16; break;
    case 16:
        if(MB_COMM_SYS_HasKind12Again(OBJ)==1 && MB_COMM_SYS_SendMessage(OBJ,3,0)==1) {
            p[0x24]=17; p[0x27]=0;
        }
        break;
    case 17:
        if(MB_COMM_SYS_HasKind14(OBJ)==1 && MB_COMM_SYS_SendMessage(OBJ,4,0)==1) p[0x24]=19;
        break;
    case 18: break;
    case 19: if(MB_COMM_SYS_HasKind4(OBJ)==1) ((struct Obj01529 *)p)->f20=22; break;
    }
}
