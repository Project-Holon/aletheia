/*
 * unit: yes
 * function: func_021F62FC,func_021F6324
 * address: 0x021F62FC
 * packet: pkt_ov215_021F62FC
 * region: ov215
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * extent: includes cleared tiny follower func_021F6324; no further code included.
 * symbols:
 *   func_0201FDA0 0x0201FDA0 thumb
 */
struct WinDat;
struct BmpMenu;
extern struct BmpMenu *func_0201FDA0(const struct WinDat *,unsigned short,unsigned char,unsigned char,unsigned short);
int func_021F62FC(int a,char *p){*(struct BmpMenu **)(p+0x78)=func_0201FDA0((const struct WinDat *)(p+0x70),*(unsigned *)(p+0x60),2,0,*(unsigned short *)p);*(int *)(p+0x7c)=2;*(int *)(p+0x20)=1;return 1;}
int func_021F6324(int a,char *p){return *(int *)(p+0x7c);}
