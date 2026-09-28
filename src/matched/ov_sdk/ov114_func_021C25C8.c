/*
 * function: func_021C25C8
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
 *   g_021CEDCC  0x021CEDCC  data
 *   g_021CEDD0  0x021CEDD0  data
 *   g_021CEDE4  0x021CEDE4  data
 *   g_021CEE28  0x021CEE28  data
 *   g_021CEE34  0x021CEE34  data
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

extern char g_021CEDCC[];
extern char g_021CEDD0[];
extern char g_021CEDE4[];
extern char g_021CEE28[];
extern char g_021CEE34[];

char *func_021C25C8(struct Conn *connection)
{
	struct Post *post = connection->post;

	if (post == 0)
		return g_021CEDCC;
	if (post->f14)
		return g_021CEDD0;
	if (post->f0c)
		return g_021CEDE4;
	if (post->f10)
		return g_021CEE28;
	return g_021CEE34;
}
