# The language cartridges

Pokémon Black and White were sold in one cartridge per language. The English cartridge
(USA, Europe) is the reference: its layout is `layout/` and every address in `src/game` is an
English Black address. The same source builds the French, German, Italian and Spanish
cartridges of both games, byte-identical to the dumps in [ROMS.md](ROMS.md).

## How much differs

Measured against the English cartridge of the same game:

- The file system has the same 247 files in the same order. 51 to 57 files hold other content
  (text, fonts, graphics with text). The two download-play images carry the language in their
  name.
- The ARM9 module is 64 to 256 bytes shorter, so every overlay loads lower. 4 to 10 overlays
  change size.
- About 140 functions differ. About 40 of them only load the language id. The DSi code is the
  same in every cartridge.
- Black and White differ in the same places in every language, so the version and the
  language are two independent switches.

## The source

`src/game/version.h` defines the switches. The tools pass them from the target
(`tools/targets.py`):

| Name | Meaning |
|---|---|
| `VERSION` | `VERSION_BLACK` (default) or `VERSION_WHITE` |
| `LANGUAGE` | `LANGUAGE_ENGLISH` (default), `_FRENCH` 3, `_ITALIAN` 4, `_GERMAN` 5, `_SPANISH` 7 (`_JAPANESE` 1) |
| `PM_LANG_ID` | the cartridge's language id, stored in the player record, profiles, mail and Wi-Fi data |
| `PM_LANG_MONTH_AS_NAME` | French, Italian and German write a month as its name in dates |
| `PM_LANG_VERSION_KEY` | the Wi-Fi match key: language and version |

A site that differs in one file uses a constant chosen by an `#if LANGUAGE` chain near the top
of the file, with the English value in the `#else`. Most are text positions and widths. A few
are real code: the glyph decoder of French, German and Italian (`gf_font.c`), the species-name
setters of the word set (`wordset.c`), the plural rules of item messages
(`scrcmd_proc_fld.c`), the size of the easy-chat search result list (`pmsi_search.c`) and the
similar-word group count (`pms_word.c`).

## The tools

Every link and ROM tool takes `--target NAME` or `ALETHEIA_TARGET`. Addresses are planned in
English Black and mapped to the target (`tools/white_map.py`): by aligning the two images, and
by the symbol maps of the regions that already link for that target. The data after the code
is generated from the target's own extract with English Black's object structure; tables whose
size changes per language (the easy-chat word lists, some Pokédex arrays) are taken as one block
from the target. `romlink.py --relink` links a region that failed a second time, after the
regions whose addresses it uses have linked.
