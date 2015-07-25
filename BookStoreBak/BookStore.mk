##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=BookStore
ConfigurationName      :=Debug
WorkspacePath          := "/Users/hganguyen/mySource/cpp"
ProjectPath            := "/Users/hganguyen/mySource/cpp/BookStore"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Giang Nguyen Hoang
Date                   :=25/07/2015
CodeLitePath           :="/Users/hganguyen/Library/Application Support/codelite"
LinkerName             :=g++
SharedObjectLinkerName :=g++ -dynamiclib -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-gstab
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :="BookStore.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcus
CXX      := g++
CC       := gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := as


##
## User defined environment variables
##
CodeLiteDir:=/Users/hganguyen/Downloads/codelite.app/Contents/SharedSupport/
Objects0=$(IntermediateDirectory)/cpp_Book.cpp$(ObjectSuffix) $(IntermediateDirectory)/cpp_BookCopy.cpp$(ObjectSuffix) $(IntermediateDirectory)/cpp_Borrower.cpp$(ObjectSuffix) $(IntermediateDirectory)/cpp_DataHolder.cpp$(ObjectSuffix) $(IntermediateDirectory)/cpp_LibraryManager.cpp$(ObjectSuffix) $(IntermediateDirectory)/cpp_Loan.cpp$(ObjectSuffix) $(IntermediateDirectory)/cpp_main.cpp$(ObjectSuffix) $(IntermediateDirectory)/cpp_Utilities.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/cpp_Book.cpp$(ObjectSuffix): ../Book.cpp $(IntermediateDirectory)/cpp_Book.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/hganguyen/mySource/cpp/Book.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/cpp_Book.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/cpp_Book.cpp$(DependSuffix): ../Book.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/cpp_Book.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/cpp_Book.cpp$(DependSuffix) -MM "../Book.cpp"

$(IntermediateDirectory)/cpp_Book.cpp$(PreprocessSuffix): ../Book.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/cpp_Book.cpp$(PreprocessSuffix) "../Book.cpp"

$(IntermediateDirectory)/cpp_BookCopy.cpp$(ObjectSuffix): ../BookCopy.cpp $(IntermediateDirectory)/cpp_BookCopy.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/hganguyen/mySource/cpp/BookCopy.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/cpp_BookCopy.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/cpp_BookCopy.cpp$(DependSuffix): ../BookCopy.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/cpp_BookCopy.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/cpp_BookCopy.cpp$(DependSuffix) -MM "../BookCopy.cpp"

$(IntermediateDirectory)/cpp_BookCopy.cpp$(PreprocessSuffix): ../BookCopy.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/cpp_BookCopy.cpp$(PreprocessSuffix) "../BookCopy.cpp"

$(IntermediateDirectory)/cpp_Borrower.cpp$(ObjectSuffix): ../Borrower.cpp $(IntermediateDirectory)/cpp_Borrower.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/hganguyen/mySource/cpp/Borrower.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/cpp_Borrower.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/cpp_Borrower.cpp$(DependSuffix): ../Borrower.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/cpp_Borrower.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/cpp_Borrower.cpp$(DependSuffix) -MM "../Borrower.cpp"

$(IntermediateDirectory)/cpp_Borrower.cpp$(PreprocessSuffix): ../Borrower.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/cpp_Borrower.cpp$(PreprocessSuffix) "../Borrower.cpp"

$(IntermediateDirectory)/cpp_DataHolder.cpp$(ObjectSuffix): ../DataHolder.cpp $(IntermediateDirectory)/cpp_DataHolder.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/hganguyen/mySource/cpp/DataHolder.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/cpp_DataHolder.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/cpp_DataHolder.cpp$(DependSuffix): ../DataHolder.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/cpp_DataHolder.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/cpp_DataHolder.cpp$(DependSuffix) -MM "../DataHolder.cpp"

$(IntermediateDirectory)/cpp_DataHolder.cpp$(PreprocessSuffix): ../DataHolder.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/cpp_DataHolder.cpp$(PreprocessSuffix) "../DataHolder.cpp"

$(IntermediateDirectory)/cpp_LibraryManager.cpp$(ObjectSuffix): ../LibraryManager.cpp $(IntermediateDirectory)/cpp_LibraryManager.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/hganguyen/mySource/cpp/LibraryManager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/cpp_LibraryManager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/cpp_LibraryManager.cpp$(DependSuffix): ../LibraryManager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/cpp_LibraryManager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/cpp_LibraryManager.cpp$(DependSuffix) -MM "../LibraryManager.cpp"

$(IntermediateDirectory)/cpp_LibraryManager.cpp$(PreprocessSuffix): ../LibraryManager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/cpp_LibraryManager.cpp$(PreprocessSuffix) "../LibraryManager.cpp"

$(IntermediateDirectory)/cpp_Loan.cpp$(ObjectSuffix): ../Loan.cpp $(IntermediateDirectory)/cpp_Loan.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/hganguyen/mySource/cpp/Loan.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/cpp_Loan.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/cpp_Loan.cpp$(DependSuffix): ../Loan.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/cpp_Loan.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/cpp_Loan.cpp$(DependSuffix) -MM "../Loan.cpp"

$(IntermediateDirectory)/cpp_Loan.cpp$(PreprocessSuffix): ../Loan.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/cpp_Loan.cpp$(PreprocessSuffix) "../Loan.cpp"

$(IntermediateDirectory)/cpp_main.cpp$(ObjectSuffix): ../main.cpp $(IntermediateDirectory)/cpp_main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/hganguyen/mySource/cpp/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/cpp_main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/cpp_main.cpp$(DependSuffix): ../main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/cpp_main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/cpp_main.cpp$(DependSuffix) -MM "../main.cpp"

$(IntermediateDirectory)/cpp_main.cpp$(PreprocessSuffix): ../main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/cpp_main.cpp$(PreprocessSuffix) "../main.cpp"

$(IntermediateDirectory)/cpp_Utilities.cpp$(ObjectSuffix): ../Utilities.cpp $(IntermediateDirectory)/cpp_Utilities.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/hganguyen/mySource/cpp/Utilities.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/cpp_Utilities.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/cpp_Utilities.cpp$(DependSuffix): ../Utilities.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/cpp_Utilities.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/cpp_Utilities.cpp$(DependSuffix) -MM "../Utilities.cpp"

$(IntermediateDirectory)/cpp_Utilities.cpp$(PreprocessSuffix): ../Utilities.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/cpp_Utilities.cpp$(PreprocessSuffix) "../Utilities.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


