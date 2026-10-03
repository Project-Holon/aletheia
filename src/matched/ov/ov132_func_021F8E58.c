/*
 * function: func_021F8E58
 * address: 0x021F8E58
 * packet: pkt_ov132_021F8E58
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F69E4 0x021F69E4 thumb ov112
 */
typedef unsigned short u16;typedef unsigned int u32;
typedef struct Object Object;
extern Object *func_021F69E4(u16,void *);
void func_021F8E58(char *p){int tmp[3]={0};int i;for(i=0;i<5;i++)*(int *)((u32)p+i*4+0x58)=0;*(Object **)(p+0x54)=func_021F69E4(*(u16 *)p,*(void **)(p+0xac));}
