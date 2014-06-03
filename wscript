subdirs = 'src'

def options(opt):
  opt.load('compiler_cxx')
  opt.recurse(subdirs)

def configure(conf):
  conf.env.CXXFLAGS += ['-O2', '-Wall', '-g', '-pipe']
  conf.load('compiler_cxx')

  conf.check_cfg(package = 'jubatus_core', args = '--cflags --libs')

  # for clients
  conf.check_cxx(lib = 'msgpack')
  conf.check_cxx(lib = 'jubatus_mpio')
  conf.check_cxx(lib = 'jubatus_msgpack-rpc')

  conf.recurse(subdirs)

def build(bld):
  bld.recurse(subdirs)
