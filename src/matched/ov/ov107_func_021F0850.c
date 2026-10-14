/*
 * function: MB_PARENT_SYS_LoadFileImage
 * address: 0x021F0850
 * packet: pkt_ov107_021F0850
 * region: ov107
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   FS_InitFile 0x020788AC arm
 *   FS_OpenFile 0x02078C18 arm
 *   FS_CloseFile 0x02078A80 arm
 *   MB_GetSegmentLength 0x021F2F1C arm ov107
 *   func_021F2FA0 0x021F2FA0 arm ov107
 *   func_021F3544 0x021F3544 arm ov107
 *   func_02030734 0x02030734 arm
 *   func_020307B0 0x020307B0 arm
 *   d_021F6E1C 0x021F6E1C data a4
 *   gMbParentSys 0x021F6EAC data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {u32 words[18];} File;
extern void FS_InitFile(File *);extern int FS_OpenFile(File *,const char *);extern int FS_CloseFile(File *);extern u32 MB_GetSegmentLength(void *);extern int func_021F2FA0(void *,void *,u32);extern int func_021F3544(void *,void *);extern void *func_02030734(u32,u32,int,const char *,u16);extern void func_020307B0(void *);
extern const char d_021F6E1C[];extern void *gMbParentSys[];
int MB_PARENT_SYS_LoadFileImage(const char **p){File file;File *fp;int result;
result=0;if(!*p)fp=0;else{fp=&file;FS_InitFile(fp);if(!FS_OpenFile(fp,*p))return 0;}
if(MB_GetSegmentLength(fp)){gMbParentSys[0]=func_02030734(93,65536,1,d_021F6E1C,287);if(gMbParentSys[0]){if(func_021F2FA0(fp,gMbParentSys[0],65536)){if(func_021F3544(p,gMbParentSys[0]))result=1;}if(!result)func_020307B0(gMbParentSys[0]);}}
if(fp==&file)FS_CloseFile(&file);return result;}
