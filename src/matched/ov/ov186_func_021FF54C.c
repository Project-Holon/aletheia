/*
 * function: func_021FF54C
 * address: 0x021FF54C
 * packet: pkt_ov186_021FF54C
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Extent: 252 bytes; the listing extent of 276 includes the separately filed func_021FF648 at +0xFC.
 * recoup 2026-10-05: the 8-byte payload copy as one struct assignment (W = two ints) gives the original r2/r1 load colours; two int stores gave r1/r1 (2 bytes off). Struct copy is a plausible human form. EXACT* only because of the 276 vs 252 listing extent.
 * symbols:
 *   func_02034714 0x02034714 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   func_021FFB68 0x021FFB68 thumb ov186
 *   d_02200D98 0x02200D98 data a1
 *   func_021FF900 0x021FF900 thumb ov186
 *   func_021FF938 0x021FF938 thumb ov186
 *   func_021FF968 0x021FF968 thumb ov186
 *   func_021FF99C 0x021FF99C thumb ov186
 *   func_021FF9D0 0x021FF9D0 thumb ov186
 *   func_021FFA14 0x021FFA14 thumb ov186
 *   func_021FFA40 0x021FFA40 thumb ov186
 *   func_021FFA6C 0x021FFA6C thumb ov186
 *   func_021FFA98 0x021FFA98 thumb ov186
 */
typedef struct {int a,b;} W;
typedef unsigned int   u32;
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void MI_CpuFill8(void *,unsigned,unsigned);
extern void func_021FFB68(char *,int);
extern const char d_02200D98[];
extern void func_021FF900(char *,int,char *);
extern void func_021FF938(char *,int,char *);
extern void func_021FF968(char *,int,char *);
extern void func_021FF99C(char *,int,char *);
extern void func_021FF9D0(char *,int,char *);
extern void func_021FFA14(char *,int,char *);
extern void func_021FFA40(char *,int,char *);
extern void func_021FFA6C(char *,int,char *);
extern void func_021FFA98(char *,int,char *);
void func_021FF54C(char *p,int kind,const int *values)
{
    if(kind>=9)func_02034714(d_02200D98,0,d_02200D98);
    if(values){
        *(W *)(p+0x5B0)=*(const W *)values;
    }
    MI_CpuFill8(p+0x5B8,0,0x24);
    switch(kind){
    case 0:func_021FFB68(*(char **)(p+0x5AC),(int)func_021FF900);break;
    case 1:func_021FFB68(*(char **)(p+0x5AC),(int)func_021FF938);break;
    case 2:func_021FFB68(*(char **)(p+0x5AC),(int)func_021FF968);break;
    case 3:func_021FFB68(*(char **)(p+0x5AC),(int)func_021FF99C);break;
    case 4:func_021FFB68(*(char **)(p+0x5AC),(int)func_021FF9D0);break;
    case 5:func_021FFB68(*(char **)(p+0x5AC),(int)func_021FFA14);break;
    case 6:func_021FFB68(*(char **)(p+0x5AC),(int)func_021FFA40);break;
    case 7:func_021FFB68(*(char **)(p+0x5AC),(int)func_021FFA6C);break;
    case 8:func_021FFB68(*(char **)(p+0x5AC),(int)func_021FFA98);break;
    default:func_02034714(d_02200D98,0,d_02200D98);break;
    }
}
