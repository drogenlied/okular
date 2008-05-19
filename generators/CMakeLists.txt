include (MacroLogFeature)

set(LIBSPECTRE_MINIMUM_VERSION "0.2")

macro_optional_find_package(Poppler)
macro_log_feature(POPPLER_FOUND "Poppler-Qt4" "A PDF rendering library" "http://poppler.freedesktop.org" FALSE "0.6" "Support for PDF files in okular.")

macro_optional_find_package(LibSpectre)
macro_log_feature(LIBSPECTRE_FOUND "libspectre" "A PostScript rendering library" "http://libspectre.freedesktop.org/wiki/" FALSE "${LIBSPECTRE_MINIMUM_VERSION}" "Support for PS files in okular.")

macro_optional_find_package(CHM)
macro_log_feature(CHM_FOUND "CHM" "A library for dealing with Microsoft ITSS/CHM format files" "http://www.jedrea.com/chmlib" FALSE "" "Support CHM files in okular.")

macro_optional_find_package(DjVuLibre)
macro_log_feature(DJVULIBRE_FOUND "DjVuLibre" "A library for dealing with DjVu formatted files" "http://djvulibre.djvuzone.org" FALSE "3.5.17" "Support for DjVu files in okular.")

macro_optional_find_package(TIFF)
macro_log_feature(TIFF_FOUND "libTIFF" "A library for reading and writing TIFF formatted files," "http://www.remotesensing.org/libtiff" FALSE "" "Support for TIFF files in okular.")

macro_optional_find_package(Freetype)
macro_log_feature(FREETYPE_FOUND "FreeType" "A font rendering engine" "http://www.freetype.org" FALSE "" "Provides freetype font support in the okular DVI generator.")

#we look for JPEG in kdegraphics/CMakeLists.txt
#macro_optional_find_package(JPEG)
#macro_log_feature(JPEG_FOUND "JPEG" "A library for reading and writing JPEG image files." "http://www.ijg.org" FALSE "" "Support fof PalmDB documents in okular.")
macro_optional_find_package(ZLIB)
macro_log_feature(ZLIB_FOUND "zlib" "The zlib library" "http://www.zlib.net" FALSE "" "Support for Plucker files in Okular.")

macro_optional_find_package(EPub)
macro_log_feature(EPUB_FOUND "libepub" "A library for reading EPub documents" "http://sourceforge.net/projects/ebook-tools" FALSE "" "Support for EPub documents in Okular.")

# let's enable the generators properly configured

if(POPPLER_FOUND AND HAVE_POPPLER_0_6)
  add_subdirectory(poppler)
endif(POPPLER_FOUND AND HAVE_POPPLER_0_6)

if(LIBSPECTRE_FOUND)
  add_subdirectory(spectre)
endif(LIBSPECTRE_FOUND)

add_subdirectory( kimgio )

if(CHM_FOUND)
  add_subdirectory( chm )
endif(CHM_FOUND)

if(DJVULIBRE_FOUND)
  add_subdirectory(djvu)
endif(DJVULIBRE_FOUND)

add_subdirectory(dvi)

if(TIFF_FOUND)
  add_subdirectory(tiff)
endif(TIFF_FOUND)

add_subdirectory(xps)

add_subdirectory(ooo)

add_subdirectory(fictionbook)

add_subdirectory(comicbook)

if(JPEG_FOUND AND ZLIB_FOUND)
  add_subdirectory(plucker)
endif(JPEG_FOUND AND ZLIB_FOUND)

if(EPUB_FOUND)
  add_subdirectory(epub)
endif(EPUB_FOUND)