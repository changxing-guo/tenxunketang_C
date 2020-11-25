TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    study_1.c \
    main.c \
    study_function.c \
    study_2.c

HEADERS += \
    study_1.h \
    study_function.h

DISTFILES += \
    users.txt \
    filewritetest.txt \
    test_fscanf.txt \
    testFoundTel.txt
