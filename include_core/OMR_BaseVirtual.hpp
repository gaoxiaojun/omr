/*******************************************************************************
 *
 * (c) Copyright IBM Corp. 1991, 2015
 *
 *  This program and the accompanying materials are made available
 *  under the terms of the Eclipse Public License v1.0 and
 *  Apache License v2.0 which accompanies this distribution.
 *
 *      The Eclipse Public License is available at
 *      http://www.eclipse.org/legal/epl-v10.html
 *
 *      The Apache License v2.0 is available at
 *      http://www.opensource.org/licenses/apache2.0.php
 *
 * Contributors:
 *    Multiple authors (IBM Corp.) - initial implementation and documentation
 *******************************************************************************/

#if !defined(OMR_BASEVIRTUAL_HPP_)
#define OMR_BASEVIRTUAL_HPP_

/*
 * @ddr_namespace: default
 */

#include "OMR_Base.hpp"

class OMR_BaseVirtual : public OMR_Base
{
private:
protected:
	/* Used by DDR to figure out runtime types, this is opt-in
	 * and has to be done by the constructor of each subclass.
	 * e.g. _typeId = __FUNCTION__;
	 */
	const char *_typeId;

public:
	/**
	 * Create a Base Virtual object.
	 */
	OMR_BaseVirtual()
	{
		_typeId = NULL; // If NULL DDR will print the static (compile-time) type.
	};

	/*
	 * Required to force OMR_BaseVirtual to have a vtable, otherwise
	 * field offsets are wrong in DDR (due to addition of the vpointer
	 * in derived classes). Using a virtual destructor causes linking
	 * issues because we never use -lstdc++ (outside tests) and the
	 * delete implementation will be missing (e.g. needed by stack allocation)
	 */
	virtual void emptyMethod() { /* No implementation */ };
};

#endif /* OMR_BASEVIRTUAL_HPP_ */
