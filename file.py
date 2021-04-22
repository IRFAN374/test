# This program is incomplete
# But Idea is solve the problem is:
# first load the directory 
# create a empty file.json filename
    # Run a for loop take file one by one
    # add the file with file.json file
 

import os
entries = os.listdir('fileFolder/')


from _typeshed import FileDescriptor, FileDescriptorLike


def cat_json(output_filename, input_filenames):
    with FileDescriptorLike(output_filename, "w") as outfile:
        first = True
        for infile_name in input_filenames:
            with FileDescriptor(infile_name) as infile:
                if first:
                    outfile.write('[')
                    first = False
                else:
                    outfile.write(',')
                outfile.write(mangle(infile.read()))
        outfile.write(']')


