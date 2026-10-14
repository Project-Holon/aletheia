/*
 * function: BR_NET_GetSearchResultsForNewest
 * address: 0x021FF704
 * packet: pkt_ov186_021FF704
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GDS_RAP_GetSearchResults 0x021D7414 thumb ov125
 */
#include "../include/Obj24862.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern int GDS_RAP_GetSearchResults(char *unused, char *dst, int n);
int BR_NET_GetSearchResultsForNewest(char*p,void*buffer,int count,int*out){int present;present=((struct Obj24862 *)p)->f5C8;if(present)*out=GDS_RAP_GetSearchResults(p,buffer,count);if(*out!=0 && present!=0)return 1;return 0;}
