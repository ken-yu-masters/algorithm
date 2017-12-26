#!/bin/csh
set projectName = "1.twoSum"
set sourceFileName = "main.cpp 1.twoSum.cpp"
set options = ""
set gccBasePath = '/grid/common/pkgsData/gcc-v6.3.0/Linux/RHEL6.0-2016-x86_64/'
set options = "QMAKE_CXX=${gccBasePath}/bin/g++"
set options = "${options} LINK=$gccBasePath/bin/g++"
set options = "${options} QMAKE_CC=$gccBasePath/bin/gcc"
set options = "${options} QMAKE_LINK_C=$gccBasePath/bin/gcc"
set options = "${options} QMAKE_RPATHDIR+=$gccBasePath/lib64"
#set options = "${options} CONFIG+=console"
#set options = "${options} QMAKE_CXXFLAGS+=-std=c++11"
set options = "${options} CONFIG+=c++11"
echo "$options"

#1: generate project file
set projectFile = ${projectName}.pro
if ( -f $projectFile ) then
    echo  "Warnning: QT project file : $projectFile exsit! Not generate new."
else
    echo "INFO: generating project file ..."
    echo "qmake -project ${sourceFileName} -o $projectFile $options"
    qmake -project -o $projectFile $options
endif

#generate new linux project-file/Makefile
if ( -d linux ) then
    echo "ERROR: linux directory exist. not generating new linux Makefile."
    exit
else
    mkdir linux
    cd linux

    echo "INFO : generating new linux Makefile ..."
    qmake ../$projectFile
    
    cd ..
endif

echo "INFO: successfully generated the Makefile."
