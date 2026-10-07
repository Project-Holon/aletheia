/*
 * function: func_021F0850
 * address: 0x021F0850
 * packet: pkt_ov107_021F0850
 * region: ov107
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020788AC 0x020788AC arm
 *   func_02078C18 0x02078C18 arm
 *   func_02078A80 0x02078A80 arm
 *   func_021F2F1C 0x021F2F1C arm ov107
 *   func_021F2FA0 0x021F2FA0 arm ov107
 *   func_021F3544 0x021F3544 arm ov107
 *   func_02030734 0x02030734 arm
 *   func_020307B0 0x020307B0 arm
 *   d_021F6E1C 0x021F6E1C data a4
 *   d_021F6EAC 0x021F6EAC data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {u32 words[18];} File;
extern void func_020788AC(File *);extern int func_02078C18(File *,const char *);extern int func_02078A80(File *);extern u32 func_021F2F1C(void *);extern int func_021F2FA0(void *,void *,u32);extern int func_021F3544(void *,void *);extern void *func_02030734(u32,u32,int,const char *,u16);extern void func_020307B0(void *);
extern const char d_021F6E1C[];extern void *d_021F6EAC[];
int func_021F0850(const char **p){File file;File *fp;int result;
result=0;if(!*p)fp=0;else{fp=&file;func_020788AC(fp);if(!func_02078C18(fp,*p))return 0;}
if(func_021F2F1C(fp)){d_021F6EAC[0]=func_02030734(93,65536,1,d_021F6E1C,287);if(d_021F6EAC[0]){if(func_021F2FA0(fp,d_021F6EAC[0],65536)){if(func_021F3544(p,d_021F6EAC[0]))result=1;}if(!result)func_020307B0(d_021F6EAC[0]);}}
if(fp==&file)func_02078A80(&file);return result;}
