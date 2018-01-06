from distutils.core import setup

setup(name='nmaya',
	  description="""A protocol for arranging stuff""",
	  version='0.1',
	  packages=['nmaya'],
	  package_dir={'': 'bindings/python'},
)
