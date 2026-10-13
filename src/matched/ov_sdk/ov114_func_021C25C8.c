/*
 * function: ghiPostGetContentType
 * address:  0x021C25C8
 * packet:   pkt_ov114_021C25C8
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ghiPostGetContentType (libdwcgsghttp.TWL.HYB.a(ghttppost.o))
 *
 * symbols:
 *   sGhttpPostEmptyContentType  0x021CEDCC  data
 *   sGhttpApplicationDime  0x021CEDD0  data
 *   sGhttpMultipartFormDataBoundaryQr  0x021CEDE4  data
 *   sGhttpTextXml  0x021CEE28  data
 *   sGhttpApplicationXWwwFormUrlencoded  0x021CEE34  data
 */

struct Post {
	unsigned char pad0[0xc];
	int f0c;
	int f10;
	int f14;
};

struct Conn {
	unsigned char pad0[0x164];
	struct Post *post;
};

extern char sGhttpPostEmptyContentType[];
extern char sGhttpApplicationDime[];
extern char sGhttpMultipartFormDataBoundaryQr[];
extern char sGhttpTextXml[];
extern char sGhttpApplicationXWwwFormUrlencoded[];

char *ghiPostGetContentType(struct Conn *connection)
{
	struct Post *post = connection->post;

	if (post == 0)
		return sGhttpPostEmptyContentType;
	if (post->f14)
		return sGhttpApplicationDime;
	if (post->f0c)
		return sGhttpMultipartFormDataBoundaryQr;
	if (post->f10)
		return sGhttpTextXml;
	return sGhttpApplicationXWwwFormUrlencoded;
}
