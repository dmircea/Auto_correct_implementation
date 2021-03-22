#!/usr/bin/python3
#############################################################################
#           MAKE PYTHON PROGRAM FOR COMPILING C++ CODE                  #####
#############################################################################
import os

#   FOR DEBUGGING ONLY
def log(output, debug = False):
    if(debug):
        print(output)

#   For future purposes
def get_exclusion_list():
    pass

#   Look through each folder and get .cpp file names in a list
#   This function should return a list of all source files
def get_all_source_files(root = '.'):
    print('Looking for source files...')
    directories = os.listdir(root)

    for i in range(len(directories)):
        directories[i] = root + '/' + directories[i]

    source_files = []

    log(directories)
    log(directories[1])
    log(directories[1][-4:])
    log(len(directories[1][-4:]))
    log(os.stat(directories[1]))
    log('Is ' + directories[1] + ' a file?')
    log(os.path.isfile(directories[1]))
    log('Is ' + directories[0] + ' a file?')
    log(os.path.isfile(directories[0]))
    log('Is ' + directories[1] + ' a directory?')
    log(os.path.isdir(directories[1]))
    log('Is ' + directories[0] + ' a directory?')
    log(os.path.isdir(directories[0]))

    for listing in directories:
        if os.path.isfile(listing) and len(listing) > 3 and listing[-4:] == '.cpp':
            source_files.append(listing)

        elif os.path.isdir(listing):
            source_files.extend(get_all_source_files(listing))

    return source_files

def main():
    print("Begin make!")
    success = True

    sources = get_all_source_files('.')

    log('The following line describes the sources of this file.')
    log(sources)

    command = 'clang++'
    version_flags = '-std=c++17'
    e_flags = '-o'
    binary = 'main'
    l_flags = '-lgtest -lpthread'

    print('Compilation start...')

    log(sources)
    log(str(sources)[1:-1])
    log(str(sources)[1:-1].replace(',','').replace('\'',''))
    execution = command + ' ' + version_flags + ' ' + str(sources)[1:-1].replace(',','').replace('\'','') + ' ' + e_flags + ' ' + binary + ' ' + l_flags

    log(execution)

    os.system(execution)

    print('End make!')

if __name__ == "__main__":
    main()
