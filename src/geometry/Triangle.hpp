/******************************************************************************
 *  File: Triangle.hpp
 *  Triangles in 3D space
 *  Copyright (c) 2008 by Changxi Zheng
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 ******************************************************************************/
#ifndef GEOMETRY_TRIANGLE_HPP
#   define GEOMETRY_TRIANGLE_HPP

#include "geometry/Point3.hpp"

#ifdef USE_NAMESPACE
namespace carbine
{
#endif

template <typename T>
class Triangle
{
    public:
        typedef Point3<T>   TVtx;

        /* =========== constructors ========== */
        Triangle(TVtx* v0, TVtx* v1, TVtx* v2)
        {
            m_vertices[0] = v0;
            m_vertices[1] = v1;
            m_vertices[2] = v2;
        }

        Triangle(TVtx* v[])
        {
            m_vertices[0] = v[0];
            m_vertices[1] = v[1];
            m_vertices[2] = v[2];
        }

        Triangle() 
        {
            m_vertices[0] = m_vertices[1] = m_vertices[2] = NULL;
        }

        /* =========== Retrival methods ============ */
        TVtx** vertices() { return m_vertices; }

        inline void init(TVtx* v0, TVtx* v1, TVtx* v2)
        {
            m_vertices[0] = v0;
            m_vertices[1] = v1;
            m_vertices[2] = v2;
        }

        TVtx* operator [] (int n)
        {
            assert(n >= 0 && n < 3);
            return m_vertices[n];
        }

        /* Using right-hand system */
        Vector3<T> weighted_normal() const // $$TESTED
        {
            return 0.5 * (*m_vertices[1] - *m_vertices[0]).crossProduct(
                    *m_vertices[2] - *m_vertices[0]);
        }

        T area() const  //$$TESTED
        {
            return 0.5 * (*m_vertices[1] - *m_vertices[0]).crossProduct(
                    *m_vertices[2] - *m_vertices[0]).length();
        }
#ifdef DIFF_DEFINE

        static inline Vector3<T> weighted_normal(const Point3<T>& v0, 
                    const Point3<T>& v1, const Point3<T>& v2)
        {  return 0.5*(v1 - v0).crossProduct(v2 - v0); }
#endif /* DIFF_DEFINE */

        static inline Vector3<T> normal(const Point3<T>& v0, 
                    const Point3<T>& v1, const Point3<T>& v2)
        {  return (v1 - v0).crossProduct(v2 - v0); }

        static inline T area(const Point3<T>& v0, 
                    const Point3<T>& v1, const Point3<T>& v2)
        {  return 0.5*(v1 - v0).crossProduct(v2 - v0).length(); }

        /*
         * compute the angle formed by v0-v1-v2
         */
        static inline T angle(const Point3<T>& v0, 
                const Point3<T>& v1, const Point3<T>& v2)
        {
            T a2 = v0.distanceSqr(v1);
            T a  = sqrt(a2);
            T b2 = v2.distanceSqr(v1);
            T b  = sqrt(b2);

            T s = 2. * a * b;
            if ( fabs(s) < 1E-12 ) 
                fprintf(stderr, "ERROR: zero-length edge encountered\n");
            return acos((a2 + b2 - v0.distanceSqr(v2)) / s);
        }

    private:
        TVtx*   m_vertices[3];
};

#ifdef USE_NAMESPACE
}
#endif
#endif
