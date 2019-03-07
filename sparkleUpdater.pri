INCLUDEPATH += $$PWD/include
DEPENDPATH += $$PWD

macx {
    QMAKE_LFLAGS += -Wl,-rpath,@loader_path/../Frameworks
    LIBS += -L$$PWD/mac -lsparkle

    LIBS += -F$$PWD/mac -framework Sparkle

    SPARKLE_DATA.files = $$PWD/mac/Sparkle.framework
    SPARKLE_DATA.path = Contents/Frameworks

    QMAKE_BUNDLE_DATA += SPARKLE_DATA
}

win32 {
    LIBS += -L$$PWD/win -lsparkle

    SPARKLE_FILE_PATH = $$absolute_path($$PWD/win/libs)

    equals(QMAKE_TARGET.arch, x86_64) {
        LIBS += -L$$PWD/win/libs/x64 -LWinSparkle
        SPARKLE_FILE_PATH = $$SPARKLE_FILE_PATH/x64/
    } else {
        LIBS += -l$$PWD/win/libs/x86 -LWinSparkle
        SPARKLE_FILE_PATH = $$SPARKLE_FILE_PATH/x86/
    }

    SPARKLE_FILE_PATH ~= s,/,\\,g
    DESTDIR  ~= s,/,\\,g

    QMAKE_POST_LINK +=  $${QMAKE_COPY} $$quote($$SPARKLE_FILE_PATH) $$quote($${DESTDIR}) $$escape_expand(\\n\\t)

    QMAKE_DISTCLEAN += $${DESTDIR}/WinSparkle.*
}
