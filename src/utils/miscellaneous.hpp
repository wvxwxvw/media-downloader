/*
 *
 *  Copyright (c) 2022
 *  name : Francis Banyikwa
 *  email: mhogomchungu@gmail.com
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <memory>
#include <QtGlobal>

namespace utils{
	namespace misc{

		template< typename Value,typename Opt >
		bool containsAny( const Value& v,const Opt& opt )
		{
			return v.contains( opt ) ;
		}

		template< typename Value,typename Opt,typename ... Opts >
		bool containsAny( const Value& v,const Opt& opt,Opts&& ... opts )
		{
			if( v.contains( opt ) ){

				return true ;
			}else{
				return misc::containsAny( v,std::forward< Opts >( opts ) ... ) ;
			}
		}

		template< typename Value,typename Opt >
		bool containsAll( const Value& v,const Opt& opt )
		{
			return v.contains( opt ) ;
		}

		template< typename Value,typename Opt,typename ... Opts >
		bool containsAll( const Value& v,const Opt& opt,Opts&& ... opts )
		{
			if( !v.contains( opt ) ){

				return false ;
			}else{
				return misc::containsAll( v,std::forward< Opts >( opts ) ... ) ;
			}
		}

		template< typename Value,typename Opt >
		bool startsWithAny( const Value& v,const Opt& opt )
		{
			return v.startsWith( opt ) ;
		}

		template< typename Value,typename Opt,typename ... Opts >
		bool startsWithAny( const Value& v,const Opt& opt,Opts&& ... opts )
		{
			if( v.startsWith( opt ) ){

				return true ;
			}else{
				return misc::startsWithAny( v,std::forward< Opts >( opts ) ... ) ;
			}
		}

		template< typename T >
		class unique_ptr
		{
		public:
			template< typename U >
			unique_ptr( U&& u ) : m_handle( std::forward< U >( u ) )
			{
			}
			unique_ptr()
			{
			}
			T& operator*() const
			{
				return m_handle.operator*() ;
			}
			T * operator->() const
			{
				return m_handle.operator->() ;
			}
			T * get() const
			{
				return m_handle.get() ;
			}
		private:
		#if QT_VERSION < QT_VERSION_CHECK( 5,10,0 )
			//Old version of Qt seems to not like unique_ptr in signals
			std::shared_ptr< T > m_handle ;
		#else
			std::unique_ptr< T > m_handle ;
		#endif
		};
	}
}
