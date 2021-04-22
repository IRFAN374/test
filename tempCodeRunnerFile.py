from _typeshed import FileDescriptor, FileDescriptorLike


# def cat_json(output_filename, input_filenames):
#     with FileDescriptorLike(output_filename, "w") as outfile:
#         first = True
#         for infile_name in input_filenames:
#             with FileDescriptor(infile_name) as infile:
#                 if first:
#                     outfile.write('[')
#                     first = False
#                 else:
#                     outfile.write(',')
#                 outfile.write(mangle(infile.read()))
#         outfile.write(']')