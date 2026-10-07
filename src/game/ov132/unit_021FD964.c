/*
 * file:     unit_021FD964.c
 * unit:     yes
 * function: func_021FD964, func_021FD974, func_021FD9A0, func_021FD9D0, func_021FD9FC, func_021FDA18, func_021FDA24, func_021FDA6C
 * address:  0x021FD964
 * region:   ov132
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021FDDEC 0x021FDDEC data a4
 */
#include "../../matched/include/Obj23306.h"

typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

typedef struct { u8 pad[0x188]; u32 flag; u32 slots[8]; } State;

u32 func_021FD964(char *p,u32 index,u32 subindex);
/* A byte parameter keeps the store input live without an entry truncation. */ void func_021FD974(char *p,u32 key,u8 value);
unsigned char func_021FD9A0(unsigned char *p,unsigned char key);
void func_021FD9D0(unsigned char *p,unsigned char key);
int func_021FD9FC(char *p);
void func_021FDA18(unsigned char *p);
void func_021FDA24(State *p, u32 a, u32 b, u32 c);
unsigned char *func_021FDA6C(void *h);
extern unsigned char d_021FDDEC[];

u32 func_021FD964(char *p,u32 index,u32 subindex){p=p+index*0x30;return *(u8 *)(p+subindex+0x73);}

/* A byte parameter keeps the store input live without an entry truncation. */
void func_021FD974(char *p,u32 key,u8 value) {u8 i;for(i=0;i<4;i++){if(key==*(u8 *)((u32)p+i*0x30+0x72)){*(int *)((u32)p+i*0x30+0x6c)=1;*(u8 *)((u32)p+i*0x30+0x70)=value;}}}

unsigned char func_021FD9A0(unsigned char *p,unsigned char key) {unsigned char i;for(i=0;i<4;i++){if(p[(unsigned int)i*48+114]==key) return *(unsigned char *)((unsigned int)p+(unsigned int)i*48+113);}return 10;}

void func_021FD9D0(unsigned char *p,unsigned char key) {unsigned char i;for(i=0;i<4;i++){if(p[(unsigned int)i*48+114]==key) p[(unsigned int)i*48+113]=10;}}


int func_021FD9FC(char *p)
{
    unsigned int i = ((struct Obj23306 *)p)->f180;

    if (i < 4)
        return *(u8 *)(p + i * 0x30 + 0x72);
    return 4;
}

void func_021FDA18(unsigned char *p) {p[384]=4;}

void func_021FDA24(State *p, u32 a, u32 b, u32 c)
{
    u8 i;
    for (i = 0; i < 8; i++) {
        if (p->slots[i] == 0xffff) {
            p->slots[i] = (c << 16) + (a << 8) + b;
            p->flag = 1;
            return;
        }
    }
}

unsigned char *func_021FDA6C(void *h) {return d_021FDDEC;}
